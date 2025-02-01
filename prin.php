<html>
    <body>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $corre = $_POST['Corr1'];
        $pass = $_POST['Pass1'];

        // Validar y procesar los datos recibidos
        if (!empty($corre) && !empty($pass)) {
            echo "Nombre: " . htmlspecialchars($corre) . "<br>";
            echo "Email: " . htmlspecialchars($pass) . "<br>";
        } else {
            echo "Por favor, complete todos los campos.";
        }
    } else {
        echo "Método de solicitud no válido.";
    }
    ?>
    </body>
</html>