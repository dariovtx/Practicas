<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{
include_once 'encabezado1.php';
if(isset($_POST['txt_nom' ])==true)
{//guradar en la bdd
echo '<meta http-equiv="Content-Type" content="text/html; charset=Dutf-8"/>';
include 'conexion.php';
mysqli_select_db($conexion, "bdd_agencia_viajes");
$cod=$_POST['txt_cod'];
$ced=$_POST['txt_ced'];
$nom=$_POST['txt_nom'];
$ape=$_POST['txt_ape'];
$dir=$_POST['txt_dir'];
$tel=$_POST['txt_tel'];
$fec=$_POST['txt_fec'];
$ori=$_POST['cb_ori'];
$des=$_POST['cb_des'];
$obs=$_POST['txt_obs'];
mysqli_query($conexion, "update viajeros set via_ced='".$ced."',via_nom='".$nom."',via_ape='".$ape."',via_dir='".$dir."',via_tel='".$tel."'
,via_fec='".$fec."',via_ori='".$ori."',via_des='".$des."',via_obs='".$obs."'
 where via_cod='".$cod."'") or die("Error al Guardar".mysqli_error($conexion));
include_once 'mantenimiento_viajero.php';
$consultas=mysqli_query($conexion, "Select * from viajeros");
while ($fila=mysqli_fetch_array($consultas)){
echo '<tr>';
echo '<td>'.$fila[0].'</td>';
echo '<td>'.$fila[1].'</td>';
echo '<td>'.$fila[2].'</td>';
echo '<td>'.$fila[3].'</td>';
echo '<td>'.$fila[4].'</td>';
echo '<td>'.$fila[5].'</td>';
echo '<td>'.$fila[6].'</td>';
echo '<td>'.$fila[7].'</td>';
echo '<td>'.$fila[8].'</td>';
echo '<td>'.$fila[9].'</td>';
echo '</tr>';
}
echo '<br>';
mysqli_close($conexion);
echo' <br>';
echo '<br>';
echo'
<link href="css/mostrar_datos.css" type="text/css" rel="stylesheet" media="all" />
';
}else{
    include 'conexion.php';
mysqli_select_db($conexion, "bdd_agencia_viajes");
$consulta=mysqli_query($conexion, "Select * from viajeros where via_cod=".$_GET['cod']);
$fila=mysqli_fetch_array($consulta);
echo'
<body bgcolor="white">
<script type="text/javascript" src="js/funciones.js"></script>
<h1 class="register-title">EDITAR VIAJERO</h1>
<form name="cursos" class="register" action="editar_viajero.php" method="post">
<center>
<table>
<tr>
<td> <b> Código: </b> </td>
<td> <input type="text" name="txt_cod" value="'.$fila[0].'"readonly></td>
</tr>
<tr>
<td> <b> Cedula/DNI: </b> </td>
<td> <input type="text" name="txt_ced" value="'.$fila[1].'" onkeypress="return sololetras (event) "></td>
</tr>
<td> <b> Nombre: </b> </td>
<td> <input type="text" name="txt_nom" value="'.$fila[2].'"></td>
</tr>
<tr>
<tr>
<td> <b> Apellido: </b> </td>
<td> <input type="text" name="txt_ape" value="'.$fila[3].'"readonly></td>
</tr>
<tr>
<td> <b> Dirección: </b> </td>
<td> <input type="text" name="txt_dir" value="'.$fila[4].'" onkeypress="return sololetras (event) "></td>
</tr>
<td> <b> Teléfono: </b> </td>
<td> <input type="text" name="txt_tel" value="'.$fila[5].'"></td>
</tr>
<tr>
<tr>
<td> <b> Fecha: </b> </td>
<td> <input type="date" name="txt_fec" value="'.$fila[6].'"readonly></td>
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
</select></tr>

<tr>
<td><b> Destino:
</b></td>
<td>
<select name="cb_des"> ';
$consulta=mysqli_query($conexion, "Select * from destinos");
while ($fila=mysqli_fetch_array($consulta)) {
echo '<option value='.$fila[0].'>'.$fila[1].'</option>';
}

echo '
</select></tr>

<tr>
<td> <b> Observación: </b> </td>
<td> <input type="text" name="txt_obs" value="'.$fila[8].'"></td>

</td>
</tr>
<tr>
<td>
</td>
<td><input type="submit" class="button" name="b_guardar" value="GUARDAR"></td>
</table>
</center>
</form>
<link href="css/ingreso_datos.css" type="text/css" rel="stylesheet" media="all" />
</body>
<br>
';
}
include_once 'pie.php';
}
?>