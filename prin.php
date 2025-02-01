<html>
    <body>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Recibir datos del formulario HTML
        $nombre = $_POST['nombre'];
        $email = $_POST['email'];
        $mensaje = $_POST['mensaje'];

        // Validar y procesar los datos recibidos
        if (!empty($nombre) && !empty($email) && !empty($mensaje)) {
            // Aquí puedes agregar el código para procesar los datos, como guardarlos en una base de datos
            echo "Nombre: " . htmlspecialchars($nombre) . "<br>";
            echo "Email: " . htmlspecialchars($email) . "<br>";
            echo "Mensaje: " . htmlspecialchars($mensaje) . "<br>";
        } else {
            echo "Por favor, complete todos los campos.";
        }
    } else {
        echo "Método de solicitud no válido.";
    }
    ?>
    </body>
</html>