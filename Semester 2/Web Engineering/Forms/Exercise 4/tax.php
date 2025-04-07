<?php

    $gross = $_GET["gross"];
    $net = round($gross / 1.19, 2);

    echo "Nettopreis: $net €";