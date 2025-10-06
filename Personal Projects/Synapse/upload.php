<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $targetDir = "uploads/"; // Ensure this directory exists and is writable
    $targetFile = $targetDir . basename($_FILES["pdfFile"]["name"]);
    $uploadOk = 1;
    $fileType = strtolower(pathinfo($targetFile, PATHINFO_EXTENSION));

    // Check if the file is a PDF
    if ($fileType != "pdf") {
        echo "<p>Sorry, only PDF files are allowed.</p>";
        $uploadOk = 0;
    }

    // Attempt to upload the file
    if ($uploadOk == 1) {
        if (!is_dir($targetDir)) {
            mkdir($targetDir, 0777, true); // Create the directory if it doesn't exist
        }

        if (move_uploaded_file($_FILES["pdfFile"]["tmp_name"], $targetFile)) {
            // Redirect to index.html with the uploaded file path as a query parameter
            header("Location: index.html?file=" . urlencode($targetFile));
            exit();
        } else {
            echo "<p>Sorry, there was an error uploading your file.</p>";
        }
    }
} else {
    // If no file is uploaded, find the most recent file in the uploads directory
    $targetDir = "uploads/";
    $files = glob($targetDir . "*.pdf"); // Get all PDF files in the directory
    usort($files, function ($a, $b) {
        return filemtime($b) - filemtime($a); // Sort by last modified time, descending
    });

    if (!empty($files)) {
        // Redirect to index.html with the most recent file as a query parameter
        header("Location: index.html?file=" . urlencode($files[0]));
        exit();
    } else {
        // No files found, redirect with no file parameter
        header("Location: index.html");
        exit();
    }
}
?>

