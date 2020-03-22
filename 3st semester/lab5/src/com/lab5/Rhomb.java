package com.lab5;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Rhomb extends Rectangle {

    public Rhomb(double x, double y, double l, double h, int count) {
        super(x, y, l, h, count);
    }

    @Override
    public void Show(int sh, GraphicsContext gc) {
        if (sh==1) {
            gc.setFill(Color.PLUM);
            gc.fillPolygon(new double[] {getX(), getX()+this.getLength()/2, getX(), getX()-this.getLength()/2},
                    new double[] {getY()-this.getHeight()/2, getY(), getY()+this.getHeight()/2, getY()},4);
        }
        else if (sh==2) {
            gc.setFill(Color.CHARTREUSE);
            gc.fillPolygon(new double[] {getX(), getX()+this.getLength()/2, getX(), getX()-this.getLength()/2},
                    new double[] {getY()-this.getHeight()/2, getY(), getY()+this.getHeight()/2, getY()},4);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillPolygon(new double[] {getX(), getX()+this.getLength()/2+1, getX(), getX()-this.getLength()/2-1},
                    new double[] {getY()-this.getHeight()/2-1, getY(), getY()+this.getHeight()/2+1, getY()},4);
        }
    }
}
