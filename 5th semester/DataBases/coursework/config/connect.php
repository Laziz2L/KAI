<?php
$connect = mysqli_connect('localhost', 'root', '', 'cinema_bd');

if (!$connect) {
    echo 'Error connect to database';
}