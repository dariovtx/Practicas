-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 13-02-2020 a las 13:53:17
-- Versión del servidor: 10.4.10-MariaDB
-- Versión de PHP: 7.3.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `bdd_agencia_viajes`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `destinos`
--

DROP TABLE IF EXISTS `destinos`;
CREATE TABLE IF NOT EXISTS `destinos` (
  `des_cod` int(11) NOT NULL AUTO_INCREMENT,
  `des_ciu` varchar(25) COLLATE utf8_spanish_ci NOT NULL,
  `des_dir` varchar(40) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`des_cod`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `destinos`
--

INSERT INTO `destinos` (`des_cod`, `des_ciu`, `des_dir`) VALUES
(2, 'Buenos Aires', 'parana 123');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `origen`
--

DROP TABLE IF EXISTS `origen`;
CREATE TABLE IF NOT EXISTS `origen` (
  `ori_cod` int(11) NOT NULL AUTO_INCREMENT,
  `ori_ciu` varchar(25) COLLATE utf8_spanish_ci NOT NULL,
  `ori_dir` varchar(40) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`ori_cod`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `origen`
--

INSERT INTO `origen` (`ori_cod`, `ori_ciu`, `ori_dir`) VALUES
(1, 'Santa ', '9 de julio 22');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

DROP TABLE IF EXISTS `usuario`;
CREATE TABLE IF NOT EXISTS `usuario` (
  `usu_cod` int(11) NOT NULL AUTO_INCREMENT,
  `usu_nom` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `usu_ema` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `usu_pas` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`usu_cod`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `usuario`
--

INSERT INTO `usuario` (`usu_cod`, `usu_nom`, `usu_ema`, `usu_pas`) VALUES
(1, 'admin', 'admin@hotmail.com', 'admin12');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `viajeros`
--

DROP TABLE IF EXISTS `viajeros`;
CREATE TABLE IF NOT EXISTS `viajeros` (
  `via_cod` int(11) NOT NULL AUTO_INCREMENT,
  `via_ced` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `via_nom` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `via_ape` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `via_dir` varchar(30) COLLATE utf8_spanish_ci NOT NULL,
  `via_tel` varchar(15) COLLATE utf8_spanish_ci NOT NULL,
  `via_fec` date NOT NULL,
  `via_ori` int(11) NOT NULL,
  `via_des` int(11) NOT NULL,
  `via_obs` varchar(25) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`via_cod`),
  KEY `via_ori` (`via_ori`,`via_des`),
  KEY `via_des` (`via_des`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `viajeros`
--

INSERT INTO `viajeros` (`via_cod`, `via_ced`, `via_nom`, `via_ape`, `via_dir`, `via_tel`, `via_fec`, `via_ori`, `via_des`, `via_obs`) VALUES
(1, '34827095', 'juan ', 'barrera', '9 de julio 2235', '456879', '2020-02-19', 1, 2, 'algo');

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `viajeros`
--
ALTER TABLE `viajeros`
  ADD CONSTRAINT `viajeros_ibfk_1` FOREIGN KEY (`via_des`) REFERENCES `destinos` (`des_cod`) ON UPDATE CASCADE,
  ADD CONSTRAINT `viajeros_ibfk_2` FOREIGN KEY (`via_ori`) REFERENCES `origen` (`ori_cod`) ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
