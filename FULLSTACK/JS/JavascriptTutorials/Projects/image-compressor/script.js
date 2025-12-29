const uploadInput = document.getElementById("uploadInput");
const dropArea = document.getElementById("dropArea");

const originalImg = document.getElementById("originalImg");
const compressedImg = document.getElementById("compressedImg");
const previewContainer = document.getElementById("previewContainer");
const qualitySlider = document.getElementById("qualitySlider");
const maxDimensionInput = document.getElementById("maxDimension");
const compressBtn = document.getElementById("compressBtn");
const downloadBtn = document.getElementById("downloadBtn");

let originalFile;
let compressedFileBlob;

// Drag & drop + file select
dropArea.addEventListener("click", () => uploadInput.click());

dropArea.addEventListener("dragover", (e) => {
  e.preventDefault();
  dropArea.style.background = "#ddd";
});

dropArea.addEventListener("dragleave", () => {
  dropArea.style.background = "#fff";
});

dropArea.addEventListener("drop", (e) => {
  e.preventDefault();
  dropArea.style.background = "#fff";
  if (e.dataTransfer.files[0]) handleFile(e.dataTransfer.files[0]);
});

uploadInput.addEventListener("change", (e) => {
  if (e.target.files[0]) handleFile(e.target.files[0]);
});

function handleFile(file) {
  originalFile = file;

  const reader = new FileReader();
  reader.onload = (e) => {
    originalImg.src = e.target.result;
  };
  reader.readAsDataURL(file);

  previewContainer.classList.remove("hidden");
  downloadBtn.classList.add("hidden");
}

// On compress button click
compressBtn.addEventListener("click", async () => {
  if (!originalFile) return;

  const quality = parseFloat(qualitySlider.value);
  const maxDim = parseInt(maxDimensionInput.value);

  // Options for browser-image-compression
  const options = {
    maxSizeMB: 1, // maximum size in MB (you can tune this)
    maxWidthOrHeight: maxDim,
    useWebWorker: true,
    initialQuality: quality,
    // you can keep default fileType -> it will preserve type or convert
  };

  try {
    compressedFileBlob = await imageCompression(originalFile, options);
    console.log("Original size (MB):", originalFile.size / 1024 / 1024);
    console.log("Compressed size (MB):", compressedFileBlob.size / 1024 / 1024);

    // Show compressed preview
    const compressedDataUrl = await imageCompression.getDataUrlFromFile(compressedFileBlob);
    compressedImg.src = compressedDataUrl;

    downloadBtn.classList.remove("hidden");
  } catch (err) {
    console.error("Compression error:", err);
  }
});

// Download compressed file
downloadBtn.addEventListener("click", () => {
  if (!compressedFileBlob) return;

  const link = document.createElement("a");
  link.href = URL.createObjectURL(compressedFileBlob);
  // Use original file name, or modify
  link.download = `compressed_${originalFile.name}`;
  link.click();
});
