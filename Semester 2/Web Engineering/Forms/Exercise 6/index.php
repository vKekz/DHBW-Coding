<!DOCTYPE html>
<html lang="de">
    <head>
        <title>URL-Generator</title>
    </head>
    <body>
        <?php
            $protocol = $_SERVER['REQUEST_SCHEME'];
            $server_address = $_SERVER['HTTP_HOST'];
            $path = urldecode($_SERVER['REQUEST_URI']);

            echo "Protokoll: $protocol <br>";
            echo "Server Addresse: $server_address  <br>";
            echo "Pfad: $path";
        ?>
    </body>
</html>