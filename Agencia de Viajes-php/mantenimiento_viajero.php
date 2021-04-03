<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{
include_once 'encabezado1.php';
include 'conexion.php';
$registros=mysqli_query($conexion,"select via_cod, via_ced	,via_nom ,via_ape ,via_dir,via_tel, via_fec,via_obs,ori_ciu,des_ciu
 from viajeros inner join origen on via_ori=ori_cod  inner join destinos on via_des=des_cod order by via_cod asc") or
die("Problemas en el select:".mysqli_error($conexion));
echo '<center>';
echo '<br>'.'<table border=1 bgcolor="white">';
echo '<tr>';
echo '<th colspan=14>'.'<b/>'.'ALUMNOS INGRESADOS'.'</th>';
echo '</tr>';
echo '<tr>';
echo '<th>'.'<b/>'.'CÓDIGO'.'</th>';
echo '<th>'.'<b/>'.'CEDULA/DNI'.'</th>';
echo '<th>'.'<b/>'.'NOMBRE'.'</th>';
echo '<th>'.'<b/>'.'APELLIDO'.'</th>';
echo '<th>'.'<b/>'.'DIRECCIÓN'.'</th>';
echo '<th>'.'<b/>'.'TELÉFONO'.'</th>';
echo '<th>'.'<b/>'.'FECHA'.'</th>';
echo '<th>'.'<b/>'.'ORIGEN'.'</th>';
echo '<th>'.'<b/>'.'DESTINO'.'</th>';
echo '<th>'.'<b/>'.'OBSERVACIÓN'.'</th>';
echo '<th colspan=2>'.'<b/>'.'ACCIÓN'.'</th>';
echo '</tr>';
while ($reg=mysqli_fetch_array($registros)){
echo '<tr>';
echo '<td>'.$reg['via_cod'].'</td>';
echo '<td>'.$reg['via_ced'].'</td>';
echo '<td>'.$reg['via_nom'].'</td>';
echo '<td>'.$reg['via_ape'].'</td>';
echo '<td>'.$reg['via_dir'].'</td>';
echo '<td>'.$reg['via_tel'].'</td>';
echo '<td>'.$reg['via_fec'].'</td>';
echo '<td>'.$reg['ori_ciu'].'</td>';
echo '<td>'.$reg['des_ciu'].'</td>';
echo '<td>'.$reg['via_obs'].'</td>';
echo '<td><a href="editar_viajero.php?cod='.$reg['via_cod'].' "> <img src="img/editar.svg" 
width=30px height=30px title="Editar Viajero"></a></td>';
echo '<td><a href="eliminar_viajero.php?cod='.$reg['via_cod'].' "> <img src="img/eliminar.svg" 
width=30px height=30px title="Borrar Viajero"></a></td>';
echo '</tr>';

}
echo '</table';
echo '<br>';
echo '</center>';
echo '
 <link href="css/mostrar_datos.css" type="text/css" rel="stylesheet" media="all" />
 ';

    include_once 'pie.php';
}
?>