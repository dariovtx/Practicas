<?php

echo'
<html>
<div id="arriba" align="center">
<img src="img/logonom.png" height="100" width="200" title="Veoviajes">
<h2 align="center">Nos importa su destino.</h2>
</div><br><br><br>
<meta name="tipo" content="text/html;" http-equiv="content-type" charset="utf-8">
<center>
<img src="img/portada.jpg" height="270" width="1240">
</center>
<head>
<title>PRINCIPAL</title>
<link rel="icon" href="img/logo.ico">
</head>
<body>
<div id="header">
<h3>
<ul class="nav" >
<li><a href="principal.php">INICIO</a></li>

<li><a href="origen.php" title="Ingreso de Origen">ORIGEN</a>
<ul>
<li><a href="mantenimiento_origen.php" title="Mantenimiento de
Origen">Mantenimiento</a></li>
</ul>
</li>
<li><a href="destino.php" title="Ingreso de Destino">DESTINO</a>
<ul>
<li><a href="mantenimiento_destino.php" title="Mantenimiento de
Destino">Mantenimiento</a></li>
</ul>
</li>

<li><a href="viajeros.php" title="Ingreso de viajeros">VIAJEROS</a>
<ul><li><a href="mantenimiento_viajero.php" title="Mantenimiento de
viajeros">Mantenimiento</a></li>
</ul>
</li>

<li><a href="usuarios.php" title="Ingreso de Login-usuarios">USUARIOS</a>
<ul>
<li><a href="mantenimiento_usuario.php" title="Mantenimiento de
Usuarios">Mantenimiento</a></li>
</ul>
</li>
     <li>
        <a href="salir.php" title="Salir" id="salir">SALIR</a>
     </li>
     <br>
          <hr align="center" size="2" width="250" color="#b7b7b7" noshade></hr>
</ul>
<h3>
</div>
<link rel="stylesheet" href="css/encabezado.css">
</body>
<br><br>
</html>
';
?>