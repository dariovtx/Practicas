<?php
session_start();
if($_SESSION['estado']==null || $_SESSION['estado']==""){
 header('location:login.php');
}else{


include 'encabezado1.php';
echo'
    <meta charset="UTF-8">
    <meta name="tipo" content="text/html;" http-equiv="content-type">
<body bgcolor="white">
<table width="75%">
<tr>
<td>
<img src="img/img1.jpg" height="250" width="500">
</td>
<td>
</td>
<td> <font face="tahoma" color="black">
<img src="img/veo.jpg" height="50" width="100">
<br>
<p><font face="Arial" color="#s008c2e"><b>¿Quienes somos?</b></font></p>
<br>
<p>Somos una agencia de viajes con años de experiencia en la industria turística. 
En veo.com.ar podés elegir entre cientos de vuelos a destinos de todo el mundo, 
encontrar tu hotel ideal, seleccionar paquetes turísticos a medida, disfrutar de 
la mejor oferta de cruceros por el mundo y mucho más. Experimentá la facilidad de 
pagar en cuotas con todos los bancos y al precio más bajo con la mejor agencia de 
turismo de Argentina! Viví una experiencia de compra rápida, segura, fácil y empezá a 
disfrutar tus vacaciones con Avantrip.com. Ante cualquier duda o inconveniente podés 
llamar a nuestro centro de atención al cliente y recibir una respuesta rápida y satisfactoria</p>
<br>
<p><font face="Arial" color="s008c2e"><b>Fast Pass</b></font></p>
<br>
<p>Hace posible reservar antes de viajar las visitas a atracciones selectas, 
encuentros con Personajes de Disney y áreas designadas para disfrutar de fuegos
 artificiales y desfiles selectos.Las MagicBands permiten el ingreso a su habitación 
 del hotel dentro de Disney y a los Parques Temáticos de Walt Disney World, y también 
 a las experiencias Disney Fast Pass+. Se pueden utilizar para comprar comida y mercancía 
 en lugares selectos e incluso se pueden personalizar con tu color favorito.</p>
</td>
<div align="right">
<h3><font face="Arial" color="#00028c"> SÍGUENOS EN: </font></h3>
<a href="https://www.facebook.com/"><img src="img/facebook.png" align="right" height="50"
width="50"></a>
<a href="https://twitter.com/"><img src="img/twitter.png" align="right" height="50"
width="50"></a>
<a href="https://www.instagram.com/accounts/login/2hl-es"><img src="img/instagram.png"
align="right" height="50" width="50"></a>
<a href="https://www.youtube.com/"><img src="img/youtube.png" align="right" height="50"
width="50"></a>
</div>
</tr>
</table>
<div>
<style type="text/css">
#dos{
    margin:auto;
    width:1240px;
    font-family:Arial,helvetica,sans-serif;
   background-color:white;  
}
</style>
</div>
    
</body>
';
include 'pie.php';
}
?>
