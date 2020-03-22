package com.lab1;

public class Quadratic {
    private double a; //параметры класса - поля содержащие коэффициенты уравнения
    private double b;
    private double c;

    public Quadratic(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double discriminant() {
        return b*b - 4*a*c;
    } // метод, возваращающий дискриминант уравнения

    public double result1() { //метод, возвараующий первый корень
        double d = discriminant();
        if (d==0) {
            return (-b / (2 * a));
        }  else {
            return ((-b + Math.sqrt(d)) / (2 * a));
        }
    }
    public double result2() { //метод, возвараующий второй корень
        double d = discriminant();
        if (d==0) {
            return (-b / (2 * a));
        }  else {
            return ((-b - Math.sqrt(d)) / (2 * a));
        }
    }
}
