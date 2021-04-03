<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{
include_once 'encabezado1.php';
include 'conexion.php';
mysqli_select_db($conexion, "bdd_aprender21");
$consulta=mysqli_query($conexion,"Select alu_codigo, alu_nombre, alu_mail, alu_codigocurso, cur_nombrecurso from alumno,
cursos where alu_codigo='$_GET[cod]'" );
$registro=mysqli_query($conexion, "select alu_codigo, alu_nombre, alu_mail, alu_codigocurso, cur_nombrecurso from alumno
inner join cursos on alu_codigocurso=cur_codigo order by alu_codigo asc") or 
die ("Problemas con el select: ".mysqli_error($conexion));
$consultauno=mysqli_query($conexion, "Delete from alumno where alu_codigo='$_GET[cod]'");
$fila=mysqli_fetch_array($consulta);
echo'
<body>
<h1 class="register-title">SE HA ELIMINADO EL SIGUIENTE ALUMNO!</h1>
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
<td> &nbsp;'.$fila[2].' </td>
</tr>
<tr>
<td align="right"> Curso: </td>
<td> &nbsp; '.$fila[3].' </td>
</tr>
</table>
</center>
<link href="css/ingreso_datos.css" type="text/css" rel="stylesheet" media="all" />
</body>
';
include_once 'pie.php';
}
?>