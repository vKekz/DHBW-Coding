<!DOCTYPE html>
<html lang="de">
    <head>
        <title>Sales tax calculator</title>
    </head>
    <body>
        <h2>Umsatzsteuern berechnen:</h2>
        <form action="tax.php" method="get">
            <label for="gross">Bruttopreis (€):</label>
            <input type="number" id="gross" name="gross" placeholder="Bruttopreis">

            <br>

            <input type="submit" value="Berechnen">
        </form>
    </body>
</html>