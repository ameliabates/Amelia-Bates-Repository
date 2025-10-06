<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get form data
    $first_name = $_POST['firstname'];
    $last_name = $_POST['lastname'];
    $subject = $_POST['subject'];

    $to_email = "bates.amelia@gmail.com";

    // Email subject
    $email_subject = "Contact Form Submission";

    // Email content
    $email_body = "First Name: $first_name\n" .
                  "Last Name: $last_name\n" .
                  "Subject: $subject\n";

    // Headers
    $headers = "From: $first_name $last_name <noreply@example.com>";

    // Send email
    if (mail($to_email, $email_subject, $email_body, $headers)) {
        echo "Your message has been sent successfully.";
    } else {
        echo "Unable to send email. Please try again later.";
    }
}
?>
