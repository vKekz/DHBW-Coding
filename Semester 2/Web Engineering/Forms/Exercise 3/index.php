<!DOCTYPE html>
<html lang="de">
    <head>
        <title>Math trainer</title>
    </head>
    <body>
        <?php
            $x = rand(0, 100);
            $y = rand(0, 100);
            $expected = $x + $y;
        ?>

        <p><?php echo $x; ?> + <?php echo $y; ?> = ?</p>

        <form action="trainer.php" method="post">
            <label hidden for="expected"></label>
            <input hidden type="number" id="expected" name="expected" value="<?php echo $expected; ?>">

            <label for="solution">Lösung:</label>
            <input type="number" id="solution" name="solution" placeholder="Deine Lösung">

            <br>

            <input type="submit">
        </form>
    </body>
</html>