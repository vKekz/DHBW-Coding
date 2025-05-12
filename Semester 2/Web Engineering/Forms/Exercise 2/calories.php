<?php

    $gender = $_POST["gender"];
    $age = $_POST["age"];
    $height = $_POST["height"];
    $weight = $_POST["weight"];

    echo CalculateCalories($gender, $age, $height, $weight) . " kcal";

    function CalculateCalories(int $gender, int $weight, int $height, int $age) : int
    {
        return match ($gender) {
            0 => 66 + (13.7 * $weight) + (6 * $height) - (6.8 * $age),
            1 => 655 + (9.6 * $weight) + (1.8 * $height) - (4.7 * $age),
            default => -1,
        };
    }