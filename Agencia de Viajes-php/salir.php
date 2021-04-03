<?PHP
session_start();
header("cacge-control: private");
session_unset();
session_destroy();
header("location: login.php");
echo "<html></html>";
exit;
?>