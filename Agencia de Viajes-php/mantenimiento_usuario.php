<?php
session_start();
include_once 'encabezado1.php';
if($_SESSION['estado']=="admin"){

include 'conexion.php';
$consulta=mysqli_query($conexion, "Select * from usuario");
echo '<center>';
echo '<br>'.'<table border=1 bgcolor="white" align="center">';
echo '<tr>';
echo '<th colspan=9>'.'<b/>'.'USUARIO INGRESADOS'.'</th>';
echo '</tr>';
echo '<tr>';
echo '<th>'.'<b/>'.'CÓDIGO'.'</th>';
echo '<th>'.'<b/>'. 'NOMBRES'.'</th>';
echo '<th>'.'<b/>'. 'CORREO ELECTRONICO'.'</th>';
echo '<th>'.'<b/>'. 'CONTRASEÑA'.'</th>';
echo '<th colspan=2>'.'<b/>'. 'ACCIÓN'.'</th>';
echo '</tr>';
while ($fila=mysqli_fetch_array($consulta)){
echo '<tr>';
echo '<td>'.$fila[0].'</td>';
echo '<td>'.$fila[1].'</td>';
echo '<td>'.$fila[2].'</td>';
echo '<td>'.$fila[3].'</td>';

echo '<td><a href="editar_usuario.php?cod='.$fila[0].'"> <img src="img/editar.svg" height="30"
width="30" title="EDITAR USUARIO"> </a></td>';
echo '<td><a href="eliminar_usuario.php?cod='.$fila[0].'"> <img src="img/eliminar.svg" height="30"
width="30" title="ELIMINAR USUARIO"> </a></td>';

echo '</tr>';
}
echo '</table>';
echo '<br>';
echo '</center>';

echo ' <link href="css/mostrar_datos.css" type="text/css" rel="stylesheet" media="all" />';

}else{
    echo "<center>
    <br>
    <h1 style=\"color:red;\">Usted no esta autorizado.</h1>
    <a href=\"principal.php\">Volver</a>
    <br>
    </center>";
}include_once 'pie.php';
?>