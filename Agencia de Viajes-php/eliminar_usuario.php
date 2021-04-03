<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
    header('location:login.php');
   }else{include_once 'encabezado1.php';
   if($_SESSION['estado']=="admin"){
include 'conexion.php';
mysqli_select_db($conexion, "bdd_agencia_viajes");
$consulta=mysqli_query($conexion,"Select * from usuario where usu_cod=".$_GET['cod'] );
$consultauno=mysqli_query($conexion, "Delete from usuario where usu_cod=".$_GET['cod']);
$fila=mysqli_fetch_array($consulta);
echo'
<body>
<h1 class="register-title">SE HA ELIMINADO EL SIGUIENTE USUARIO</h1>
<center>
<table border=1 class="register" bgcolor="#33CEFF">
<tr>
<td align="right"> Código: </td>
<td> &nbsp;'.$fila[0].' </td>
</tr>
<tr>
<td align="right"> Nombre: </td>
<td> &nbsp; '.$fila[1].' </td>
</tr>
<tr>
<td align="right"> Correo Electrónico: </td>
<td> &nbsp; '.$fila[2].' </td>
</tr>
<tr>
<td align="right"> Contraseña: </td>
<td> &nbsp; '.$fila[3].' </td>
</tr>
</table>
</center>
<link href="css/ingreso_datos.css" type="text/css" rel="stylesheet" media="all" />
</body>
';
}else{
    echo "<center>
    <br>
    <h1 style=\"color:red;\">Usted no esta autorizado.</h1>
    <a href=\"principal.php\">Volver</a>
    <br>
    </center>";
}
include_once 'pie.php';
   }
?>