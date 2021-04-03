<?php
session_start();
$usuario= $_POST['usuario'];
$clave= $_POST['clave'];

include 'conexion.php';

$consulta="select *from usuario where usu_nom='$usuario' and usu_pas='$clave'";
$resultado=mysqli_query($conexion, $consulta);
$filas=mysqli_num_rows($resultado);
if($filas>0){
    if($usuario=="admin"){
        $_SESSION['estado']="admin";
    }else{
        $_SESSION['estado']="usuario";
    }
    
    header ("location:principal.php");
}else{
    echo"Error en la autentificación";
}
mysqli_free_result($resultado);
mysqli_close($conexion);
?>