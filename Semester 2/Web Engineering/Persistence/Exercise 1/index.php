<!DOCTYPE html>
    <html lang="de">
    <head>
        <title>Comments</title>
    </head>
    <body>
        <?php
            function get_comments(): array
            {
                if (!is_readable("comments.txt")) {
                    return [];
                }

                $content = file_get_contents("comments.txt");
                return explode(";", $content);
            }

            $comments = get_comments();
            $count = count($comments);
        ?>

        <h2>Kommentare: <?php echo $count ?></h2>
        <hr>

        <?php
            if ($count == 0) {
                echo "Keine Kommentare gefunden. <br><br>";
            } else {
                for ($i = 0; $i < $count; $i++) {
                    $comment = $comments[$i];
                    echo "<p> ($i) " . $comment . "</p>";
                }
            }
        ?>

        <form method="post" action="persistence.php">
            <label for="comment">Neuen Kommentar verfassen:</label>
            <br>
            <textarea id="comment" name="comment" rows="5" cols="50"></textarea>
            <br>
            <input type="submit" name="submit" value="Kommentar abschicken">
        </form>
    </body>
</html>