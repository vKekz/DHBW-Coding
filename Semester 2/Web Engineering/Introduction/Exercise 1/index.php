<!DOCTYPE html>
<html lang="de">
    <head>
        <title>PHP</title>
    </head>
    <body>
        <?php
            // Aufgabe 1
            echo "<h1>Aufgabe 1</h1>";
            $portions = 2;

            $ingredients = ["Spaghetti" => 250, "Knoblauchzehen" => 3, "Teelöfel Chiliflocken" => 1/4, "Esslöfel Olivenöl" => 4];
            $amounts = [250, 3, 1/4, 4];
            $type = ["Spaghetti" => "g"];

            echo "<h3>Zutaten für ein Spaghetti Gericht bei $portions Portionen</h3>";
            foreach ($ingredients as $key => $amount) {
                $type = isset($type[$key]) ? $type[$key] : '';
                $combined = ($portions * $amount) . $type . " " . $key;
                echo "- $combined <br>";
            }
        ?>
    </body>
</html>