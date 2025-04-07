<?php

    $expected = $_POST["expected"];
    $solution = $_POST["solution"];

    if ($solution == $expected) {
        echo "Richtig!";
    } else {
        echo "Falsch!";
    }