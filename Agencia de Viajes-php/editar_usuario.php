<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
    header('location:login.php');
   }else{include_once 'encabezado1.php';
   if($_SESSION['estado']=="admin"){
if(isset($_POST['txt_nom' ])==true)
{//guradar en la bdd
echo '<meta http-equiv="Content-Type" content="text/html; charset=Dutf-8"/>';
include 'conexion.php';
mysqli_select_db($conexion, "bdd_agencia_viajes");
$cod=$_POST['txt_cod'];
$nom=$_POST['txt_nom'];
$ema=$_POST['txt_ema'];
$pas=$_POST['txt_pas'];
mysqli_query($conexion, "update usuario set usu_nom='".$nom."', usu_pas= '".$pas."', usu_ema='".$ema."' 
where usu_cod='".$cod."'") or die("Error al Guardar".mysqli_error($conexion));
include_once 'mantenimiento_usuario.php';
while ($fila=mysqli_fetch_array($consulta)){
echo '<tr>';
echo '<td>'.$fila[0].'</td>';
echo '<td>'.$fila[1].'</td>';
echo '<td>'.$fila[2].'</td>';
echo '<td>'.$fila[3].'</td>';
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
$consulta=mysqli_query($conexion, "Select * from usuario where usu_cod=".$_GET['cod']);
$fila=mysqli_fetch_array($consulta);
echo'
<body bgcolor="white">
<script type="text/javascript" src="js/funciones.js"></script>
<h1 class="register-title">EDITAR USUARIO</h1>
<form name="usuarios" class="register" action="editar_usuario.php" method="post">
<center>
<table>
<tr>
<td> <b> Código: </b> </td>
<td> <input type="text" name="txt_cod" value="'.$fila[0].'"readonly></td>
</tr>
<tr>
<td> <b> Nombres: </b> </td>
<td> <input type="text" name="txt_nom" value="'.$fila[1].'" onkeypress="return sololetras (event) "></td>

</tr>
<tr>
<td> <b> Correo Electrónico: </b> </td>
<td> <input type="text" name="txt_ema" value="'.$fila[2].'" onkeypress="return sololetras (event) "></td>

</tr>
<tr>
<td> <b> Contraseña: </b> </td>
<td> <input type="text" name="txt_pas" value="'.$fila[3].'" onkeypress="return sololetras (event) "></td>

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
}}else{
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