<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{
include_once 'encabezado1.php';
include 'conexion.php';
mysqli_select_db($conexion, "bdd_agencia_viajes");
$consulta=mysqli_query($conexion,"Select * from destinos where des_cod=".$_GET['cod'] );
$consultauno=mysqli_query($conexion, "Delete from destinos where des_cod=".$_GET['cod']);
$fila=mysqli_fetch_array($consulta);
echo'
<body>
<h1 class="register-title">SE HA ELIMINADO EL SIGUIENTE CURSO</h1>
<center>
<table border=1 class="register" bgcolor="#33CEFF">
<tr>
<td align="right"> Código: </td>
<td> &nbsp;'.$fila[0].' </td>
</tr>
<tr>
<td align="right"> Ciudad: </td>
<td> &nbsp; '.$fila[1].' </td>
</tr>
<tr>
<td align="right"> Dirección: </td>
<td> &nbsp; '.$fila[2].' </td>
</tr>
</table>
</center>
<link href="css/ingreso_datos.css" type="text/css" rel="stylesheet" media="all" />
</body>
';
include_once 'pie.php';
}
?>