import { Component, ElementRef, ViewChild } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import html2canvas from 'html2canvas';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [CommonModule, FormsModule],
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  name = '';
  photoUrl: string | null = null;

  @ViewChild('nameTagRef') nameTagRef!: ElementRef;

  onFileSelected(event: any) {
    const file = event.target.files[0];
    if (file) {
      const reader = new FileReader();
      reader.onload = () => {
        this.photoUrl = reader.result as string;
      };
      reader.readAsDataURL(file);
    }
  }

  downloadTag() {
    const tagElement = this.nameTagRef?.nativeElement;
    if (!tagElement) {
      console.error('Tag element not found!');
      return;
    }

    html2canvas(tagElement, { backgroundColor: null }).then(canvas => {
      const link = document.createElement('a');
      link.download = 'name-tag.png';
      link.href = canvas.toDataURL();
      link.click();
    }).catch(err => {
      console.error('html2canvas error:', err);
    });
  }
}
