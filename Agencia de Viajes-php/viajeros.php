<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{
include_once 'encabezado1.php';
if(isset($_POST['txt_nom'])){
echo '<meta name="tipo" content-"text/html;" http-equiv="Content-Type“ charset="utf-8">';
include 'conexion.php';
mysqli_select_db($conexion,"bdd_agencia_viajes");
$ced=$_POST['txt_ced'];
$nom=$_POST['txt_nom'];
$ape=$_POST['txt_ape'];
$dir=$_POST['txt_dir'];
$tel=$_POST['txt_tel'];
$fec=$_POST['txt_fec'];
$ori=$_POST['cb_ori'];
$des=$_POST['cb_des'];
$obs=$_POST['txt_obs'];
mysqli_query($conexion,"insert into viajeros values (null,'".$ced."','".$nom."','".$ape."','".$dir."','".$tel."'
,'".$fec."','".$ori."','".$des."','".$obs."')") or die("Error al guardar" .mysqli_error($conexion));
include_once 'mantenimiento_viajero.php';
mysqli_close($conexion);
echo'<br>';
echo '<br>';
}else{

include 'conexion.php';
mysqli_select_db($conexion, "bdd_agencia_viajes");
echo'
<body bgcolor="white">
<script type="text/javascript" src="js/funciones.js"></script>
<h1 class="register-title">INGRESO DE VIAJEROS</h1>
<form name="Viajeros" class="register" action="viajeros.php" method="post">
<center>
<table>
<tr>
<td><b/> Código: </td>
<td> <input type="text" name="txt_cod" disabled="disabled"></td>
</tr>
<tr>
<td><b/> Cedula/DNI: </td>
<td> <input type="text" name="txt_ced" onkeypress="return sololetras(event)"></td>
</tr>
<tr>
<td><b/> Nombre: </td>
<td> <input type="text" name="txt_nom" onkeypress="return sololetras(event)"></td>
</tr>
<tr>
<td><b/> Apellido: </td>
<td> <input type="text" name="txt_ape" onkeypress="return sololetras(event)"></td>
</tr>
<tr>
<td><b/> Dirección: </td>
<td> <input type="text" name="txt_dir" onkeypress="return sololetras(event)"></td>
</tr>
<tr>
<td><b/> Teléfono: </td>
<td> <input type="text" name="txt_tel" onkeypress="return sololetras(event)"></td>
</tr>
<tr>
<td><b/> fecha : </td>
<td> <input type="date" name="txt_fec" onkeypress="return sololetras(event)"></td>
</tr>
<tr>
<td><b> Origen:
</b></td>
<td>
<select name="cb_ori"> ';
$consulta=mysqli_query($conexion, "Select * from origen");
while ($fila=mysqli_fetch_array($consulta)) {
echo '<option value='.$fila[0].'>'.$fila[1].'</option>';
}
echo'
</select>
<tr>
<td><b> Destino:
</b></td>
<td>
<select name="cb_des"> ';
$consulta=mysqli_query($conexion, "Select * from destinos");
while ($fila=mysqli_fetch_array($consulta)) {
echo '<option value='.$fila[0].'>'.$fila[1].'</option>';
}
echo'
</select>
<tr>
<td><b/>Observación: </td>
<td> <input type="text" name="txt_obs" onkeypress="return sololetras(event)"></td>
</tr>
</td><br>
<tr>
<td> <input type="reset" class="button" name="b_nuevo" value="NUEVO"></td>
<td><input type="submit" class="button" name="b_guardar" VALUE="GUARDAR"></td>
</tr>

</table>
</center>
</form>
<link href="css/ingreso_datos.css" type="text/css" rel="stylesheet" media="all">
</body>
';
}
include_once 'pie.php';
}
?>