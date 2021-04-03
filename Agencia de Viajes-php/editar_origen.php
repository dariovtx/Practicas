<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{
include_once 'encabezado1.php';
if(isset($_POST['txt_ciu' ])==true)
{//guradar en la bdd
echo '<meta http-equiv="Content-Type" content="text/html; charset=Dutf-8"/>';
include 'conexion.php';
mysqli_select_db($conexion, "bdd_agencia_viajes");
$cod=$_POST['txt_cod'];
$ciu=$_POST['txt_ciu'];
$dir=$_POST['txt_dir'];
mysqli_query($conexion, "update origen set ori_ciu='".$ciu."' ,ori_dir='".$dir."' where ori_cod='".$cod."'") or
die("Error al Guardar".mysqli_error($conexion));
include_once 'mantenimiento_origen.php';
while ($fila=mysqli_fetch_array($consulta)){
echo '<tr>';
echo '<td>'.$fila[0].'</td>';
echo '<td>'.$fila[1].'</td>';
echo '<td>'.$fila[2].'</td>';
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
$consulta=mysqli_query($conexion, "Select * from origen where ori_cod=".$_GET['cod']);
$fila=mysqli_fetch_array($consulta);
echo'
<body bgcolor="white">
<script type="text/javascript" src="js/funciones.js"></script>
<h1 class="register-title">EDITAR ORIGEN</h1>
<form name="origen" class="register" action="editar_origen.php" method="post">
<center>
<table>
<tr>
<td> <b> Código: </b> </td>
<td> <input type="text" name="txt_cod" value="'.$fila[0].'"readonly></td>
</tr>
<tr>
<td> <b> Nombres: </b> </td>
<td> <input type="text" name="txt_ciu" value="'.$fila[1].'" onkeypress="return sololetras (event) "></td>

</tr>
<tr>
<td> <b> Dirección: </b> </td>
<td> <input type="text" name="txt_dir" value="'.$fila[2].'" onkeypress="return sololetras (event) "></td>

</tr>
<tr>
<td>
</td>
<td><input type="submit" class="button" name="b_guardar" value="GUARDAR"></td>
</tr>
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