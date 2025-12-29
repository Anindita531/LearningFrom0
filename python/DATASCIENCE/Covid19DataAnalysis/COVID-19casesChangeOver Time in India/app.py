import streamlit as st
import pandas as pd
from prophet import Prophet
import plotly.graph_objects as go

# Load data with updated caching
@st.cache_data
def load_data():
    url = 'https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_confirmed_global.csv'
    df = pd.read_csv(url)
    return df

# Load and reshape
df = load_data()
df_long = df.drop(columns=['Province/State', 'Lat', 'Long']) \
            .melt(id_vars=['Country/Region'], var_name='ds', value_name='y')
df_long['ds'] = pd.to_datetime(df_long['ds'], format='%m/%d/%y')

# Sidebar controls
country = st.sidebar.selectbox('Select Country', df_long['Country/Region'].unique())
show_forecast = st.sidebar.checkbox("Show Forecast", value=True)

# Filter data
data_country = df_long[df_long['Country/Region'] == country].copy()

# Prepare Prophet data
prophet_df = data_country[['ds', 'y']].copy()
cap_value = prophet_df['y'].max() * 1.2
prophet_df['cap'] = cap_value

# Fit model
model = Prophet(growth='logistic', interval_width=0.95)
model.fit(prophet_df)

# Forecast
future = model.make_future_dataframe(periods=90)
future['cap'] = cap_value
forecast = model.predict(future)

# Plot
fig = go.Figure()

# Actual cases
fig.add_trace(go.Scatter(x=prophet_df['ds'], y=prophet_df['y'],
                         mode='markers', name='Actual Cases'))

# Forecast line
if show_forecast:
    fig.add_trace(go.Scatter(x=forecast['ds'], y=forecast['yhat'],
                             mode='lines', name='Forecast'))
    fig.add_trace(go.Scatter(
        x=pd.concat([forecast['ds'], forecast['ds'][::-1]]),
        y=pd.concat([forecast['yhat_upper'], forecast['yhat_lower'][::-1]]),
        fill='toself',
        fillcolor='rgba(0,123,255,0.2)',
        line=dict(color='rgba(255,255,255,0)'),
        hoverinfo="skip",
        showlegend=True,
        name='Confidence Interval'
    ))

    # ✅ Fix: Use add_shape and add_annotation instead of add_vline
    cutoff_date = prophet_df['ds'].max().to_pydatetime()
    fig.add_shape(
        type="line",
        x0=cutoff_date, x1=cutoff_date,
        y0=0, y1=1,
        line=dict(color="red", dash="dash"),
        xref="x", yref="paper"
    )
    fig.add_annotation(
        x=cutoff_date,
        y=1,
        text="End of Actual Data",
        showarrow=False,
        yanchor="bottom",
        xanchor="left",
        font=dict(color="red")
    )

fig.update_layout(title=f'COVID-19 Cases Forecast for {country}',
                  xaxis_title='Date', yaxis_title='Confirmed Cases',
                  template='plotly_white')

# Dashboard layout
st.title(" COVID-19 Forecast Dashboard")
tab1, tab2 = st.tabs(["📈 Forecast", "📊 Raw Data"])

with tab1:
    st.plotly_chart(fig, use_container_width=True)
    st.metric("Latest Cases", value=f"{prophet_df['y'].iloc[-1]:,}")
    st.metric("Peak Cases", value=f"{prophet_df['y'].max():,}")

with tab2:
    st.dataframe(prophet_df)
