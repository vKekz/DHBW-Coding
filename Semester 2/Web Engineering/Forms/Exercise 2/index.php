<!DOCTYPE html>
<html lang="de">
    <head>
        <title>Maintenance calorie calculator</title>
    </head>
    <body>
        <form action="calories.php" method="post">
            <label for="gender">Geschlecht:</label>
            <select id="gender" name="gender">
                <option value="0">Männlich</option>
                <option value="1">Weiblich</option>
            </select>

            <br>

            <label for="age">Alter:</label>
            <input type="number" id="age" name="age" placeholder="Dein Alter">

            <br>

            <label for="height">Körpergröße (cm):</label>
            <input type="number" id="height" name="height" placeholder="Deine Körpergröße">

            <label for="weight">Körpergewicht (kg):</label>
            <input type="number" id="weight" name="weight" placeholder="Dein Körpergewicht">

            <br>

            <input type="submit">
        </form>
    </body>
</html>