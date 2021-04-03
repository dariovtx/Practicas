<?php

session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{include_once 'encabezado1.php';
if($_SESSION['estado']=="admin"){
if (isset($_POST['txt_nom'])==true)
{//guradar en la bdd
echo '<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>';
include 'conexion.php';
mysqli_select_db($conexion, "bdd_agencia_viajes");
$nom=$_POST['txt_nom'];
$ema=$_POST['txt_ema'];
$pas=$_POST['txt_pas'];
$consulta="select usu_nom from usuario where usu_nom='$nom'";
    $checkusuario=mysqli_query($conexion,$consulta);
    $usuario_exist=mysqli_num_rows($checkusuario);

    $consulta1="select usu_pas from usuario where usu_pas='$pas'";
    $checkpassword=mysqli_query($conexion,$consulta1);
    $password_exist=mysqli_num_rows($checkpassword);

    $consulta="select usu_ema from usuario where usu_ema='$ema'";
    $checkemail=mysqli_query($conexion,$consulta);
    $email_exist=mysqli_num_rows($checkemail);

    if($email_exist>0|$usuario_exist>0|$password_exist>0){
        echo "<center>
    <br>
    <h1 style=\"color:red;\">El nombre de usuario/password/email ya fueron definidas por otro usuario.</h1>
    <a href=\"usuarios.php\">Volver</a>
    <br>
    </center>";
    }else{
        mysqli_query($conexion,"insert into usuario (usu_cod, usu_nom, usu_ema, usu_pas)
        values(null, '".$nom."','".$ema."','".$pas."')") or die ("Error al Guardar " .mysqli_error($conexion));
    

include_once 'mantenimiento_usuario.php';
mysqli_close($conexion);
    }
}else { //crear el formulario
echo'
<body>
<script type="text/javascript" src="js/funciones.js"></script>
<h1 class="register-title">INGRESO DE USUARIOS</h1>
<form name="usuarios" class="register" action="usuarios.php" method="post">
<center><table>
<tr> <td> <b> Código: </b> </td>
<td> <input type="text" name="txt_cod" disabled="disabled"</td>
</tr>
<tr> <td> <b> Nombres: </b> </td>
<td> <input type="text" name="txt_nom" onkeypress="return sololetras(event)"></td>
</tr>
<tr> <td> <b> Correo: </b> </td>
<td> <input type="text" name="txt_ema" onkeypress="return sololetras(event)"></td>
</tr>
<tr> <td> <b> Contraseña: </b> </td>
<td> <input type="password" name="txt_pas" onkeypress="return soloLetras(event)"></td>
</tr>
<tr>
<td> <br> <center> <input type="reset" class="button" name="b_nuevo" value="NUEVO">
<td> <br><input type="submit" class="button" name="b_guardar" value="GUARDAR"></td></center> </td>
</tr>
</table></center>
</form>
<link href="css/ingreso_datos.css" type="text/css" rel="stylesheet" media="all" />
</body>
<br>
';
}
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