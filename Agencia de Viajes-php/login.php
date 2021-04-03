<?php
include 'encabezado.php';
echo'
<!DOCTYPE html>
<html lang="es">
<meta charset="utf-8">
<meta name="viewport" content="width=device-width user-scalabre=no, initial-scale=1 minimum-scale=1, maximum-scale=1">
    <link rel="stylesheet" href="css/estilogin.css">
<title>Login</title>
<body>
    <form action="validarlog.php" method="post">
        <h2>Iniciar Sesión:</h2>
        <input type="text" placeholder="&#128272; Usuario" name="usuario">
        <input type="password" placeholder="&#128272; Contraseña" name="clave">
        <input type="submit" value="Ingresar">
    </form>
</body>
</html>
';
include 'pie.php';
?>