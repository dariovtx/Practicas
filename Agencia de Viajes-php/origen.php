<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{
include_once 'encabezado1.php';
if(isset($_POST['txt_nom'])==true){
echo '<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>';
include 'conexion.php';
mysqli_select_db($conexion,"bdd_agencia_viajes");
$nom=$_POST[ 'txt_nom'];
$dir=$_POST[ 'txt_dir'];
mysqli_query($conexion, "insert into origen values (null,'".$nom."','".$dir."')") or die("Error al
Guardar".mysqli_error($conexion));
include_once 'mantenimiento_origen.php';
mysqli_close($conexion);
}else
{ 
echo '
<body>
<script type="text/javascript" src="js/funciones.js"></script>
<h1 class="register-title">INGRESO DE ORIGEN</h1>
<form name="origen" class="register" action="origen.php" method="post">
<center><table>
<tr>
<td> <b> Código:</b> </td>
<td> <input type="text" name="txt_cod" disabled="disabled"></td>
</tr>
<tr>
<td> <b> Nombre ciudad: </b> </td>
<td> <input type="text" name="txt_nom" onkeypress="return soloLetras(event)"></td>
</tr>
<tr>
<td> <b> Dirección: </b> </td>
<td> <input type="text" name="txt_dir" onkeypress="return soloLetras(event)"></td>
</tr>
<tr>
<td> <br> <center> <input type="reset" class="button" name="b_nuevo" value="NUEVO">
<td> <br><input type="submit" class="button" name="b_guardar" value="GUARDAR"></td>
</center> </td>
</tr>
</table></center>
</form>
<link href="css/ingreso_datos.css" type="text/css" rel="stylesheet" media="all" />
</body>

<br>
';
}
include_once 'pie.php';
}
?>