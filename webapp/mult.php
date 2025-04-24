<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    if (isset($_POST["multnum"])) {
        $num = intval($_POST["multnum"]);

        if ($num < 1) {
            echo "<p>Please enter a number greater than 0.</p>";
        } else {
            echo "<h3>Multiplication Table for $num</h3>";
            echo "<table border='1' cellspacing='0' cellpadding='5'>";

            echo "<tr><th>x</th>";
            for ($i = 1; $i <= $num; $i++) {
                echo "<th>$i</th>";
            }
            echo "</tr>";
            
            for ($i = 1; $i <= $num; $i++) {
                echo "<tr><th>$i</th>";
                for ($j = 1; $j <= $num; $j++) {
                    echo "<td>" . ($i * $j) . "</td>";
                }
                echo "</tr>";
            }

            echo "</table>";
        }
    } else {
        echo "<p>Error: No number received.</p>";
    }
}
?>
