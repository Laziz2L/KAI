package com.Abdullaev4211;

import java.util.Scanner;

public class Graph {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        System.out.println("Введите размерность матрицы смежности");
        int n = in.nextInt();

        int[][] matrix = new int[n][n];

        for (int i = 0; i<matrix.length; i++) {
            for (int j = i+1; j<matrix.length; j++) {
                System.out.println("Введите 1, если есть путь между вершинами "+ (i+1) +" и "+ (j+1) + ", иначе введите 0");
                n = in.nextInt();
                matrix[i][j] = n;
                matrix[j][i] = n;
            }
        }

        System.out.println("Ваша матрица :");
        for (int i = 0; i<matrix.length; i++) {
            System.out.println(" ");
            for (int j = 0; j<matrix.length; j++) {
                System.out.print(" " + matrix[i][j] + " ");
            }
        }

        System.out.println("\n\nДля нахождения расстояния между двумя вершинами введите номер первой вершины");
        int a = in.nextInt()-1;
        System.out.println("Введите номер второй вершины");
        int b = in.nextInt()-1;
        System.out.println("Расстояние : " + GetDistance(matrix, a, b));

        int p = matrix.length;
        int q = 0;
        for (int i = 0; i<matrix.length; i++) {
            for (int j = i+1; j<matrix.length; j++) {
                if (matrix[i][j] == 1) q++;
            }
        }
        int d = (q-p+3);
        System.out.println("\nДля нахождения количества маршрутов длины "+d+" между двумя вершинами");
        System.out.println("Введите номер первой вершины");
        a = in.nextInt()-1;
        System.out.println("Введите номер второй вершины");
        b = in.nextInt()-1;
        System.out.println("Количество маршрутов : " + GetCountOfDistance(matrix, a, b, d));
    }

    static int[][] MatrixMultiply(int[][] matrix1, int[][] matrix2) {

        int[][] temp = new int[matrix1.length][matrix1.length];
        for (int i = 0; i<matrix1.length; i++) {
            for (int j = 0; j<matrix1.length; j++) {
                temp[i][j] = 0;
                for (int k = 0; k<matrix1.length; k++) {
                    temp[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return temp;
    }

    static int GetDistance(int[][] matrix, int a, int b) {

        if (matrix[a][b]==0) {
            int[][] temp = matrix;
            int c = 1;
            while (temp[a][b]==0) {
                temp = MatrixMultiply(temp, matrix);
                c++;
            }
            return c;
        }
        else {
            return 1;
        }
    }

    static int GetCountOfDistance(int[][] matrix, int a, int b, int d) {

        int[][] temp = matrix;
        for (int i=1; i<d; i++) {
            temp = MatrixMultiply(temp, matrix);
        }
        return temp[a][b];
    }
}
