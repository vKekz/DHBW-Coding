<!DOCTYPE html>
    <html lang="de">
    <head>
        <title>Color-Picker</title>
    </head>
    <body>
        <?php
            $color_file = "color.txt";

            function get_color(): string
            {
                global $color_file;
                if (!is_readable($color_file)) {
                    return "#ffffff";
                }

                return file_get_contents($color_file);
            }

            $color = get_color();
        ?>

        <form action="" method="post">
            <label for="color">Farbe auswählen:</label>
            <input id="color" name="color" type="color">
            <button type="submit">Speichern</button>

            <?php
                if (isset($_POST["color"])) {
                    file_put_contents($color_file, $_POST["color"]);
                }
            ?>

        </form>

        <style>
            body {
                background-color: <?php echo $color; ?>;
            }
        </style>
    </body>
</html>