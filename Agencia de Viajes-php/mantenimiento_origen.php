<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{
include_once 'encabezado1.php';
include 'conexion.php';
$consulta=mysqli_query($conexion, "Select * from origen");
echo '<center>';
echo '<br>'.'<table border=1 bgcolor="white" align="center">';
echo '<tr>';
echo '<th colspan=9>'.'<b/>'.'ORIGEN INGRESADO'.'</th>';
echo '</tr>';
echo '<tr>';
echo '<th>'.'<b/>'.'CÓDIGO'.'</th>';
echo '<th>'.'<b/>'. 'NOMBRES'.'</th>';
echo '<th>'.'<b/>'. 'DIRECCIÓN'.'</th>';
echo '<th colspan=2>'.'<b/>'. 'ACCIÓN'.'</th>';
echo '</tr>';
while ($fila=mysqli_fetch_array($consulta)){
echo '<tr>';
echo '<td>'.$fila[0].'</td>';
echo '<td>'.$fila[1].'</td>';
echo '<td>'.$fila[2].'</td>';
echo '<td><a href="editar_origen.php?cod='.$fila[0].'"> <img src="img/editar.svg" height="30"
width="30" title="EDITAR ORIGEN"> </a></td>';
echo '<td><a href="eliminar_origen.php?cod='.$fila[0].'"> <img src="img/eliminar.svg" height="30"
width="30" title="ELIMINAR ORIGEN"> </a></td>';
echo '</tr>';
}
echo '</table>';
echo '<br>';
echo '</center>';

echo ' <link href="css/mostrar_datos.css" type="text/css" rel="stylesheet" media="all" />';
include_once 'pie.php';
}
?>