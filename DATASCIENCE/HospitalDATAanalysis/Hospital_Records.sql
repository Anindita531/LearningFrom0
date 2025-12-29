SELECT Condition, AVG(Length_of_Stay) AS Avg_Stay
FROM Hospital_Records
GROUP BY Condition;
--Total cost of procedures by gender
SELECT Gender, SUM(Cost) AS Total_Cost
FROM Hospital_Records
GROUP BY Gender;
--Patients readmitted

SELECT COUNT(*) AS Readmitted_Patients
FROM Hospital_Records
WHERE Readmission = 'Yes';


--Mortality rate (Outcome = 'Deceased')

SELECT (COUNT(CASE WHEN Outcome = 'Deceased' THEN 1 END) * 100.0 / COUNT(*)) AS Mortality_Rate
FROM Hospital_Records;