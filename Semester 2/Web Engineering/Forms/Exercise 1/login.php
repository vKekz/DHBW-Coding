<?php
    $username = $_POST["username"];
    $password = $_POST["password"];
    $hashed_password = password_hash($password, PASSWORD_DEFAULT);

    $expected_username = "root";
    $expected_password = password_hash("123456", PASSWORD_DEFAULT);

    if (hash_equals($username, $expected_username) && password_verify($password, $expected_password)) {
        echo "Willkommen zurück $username!";
    } else {
        echo "Falscher Benutzername oder falsches Passwort!";
    }