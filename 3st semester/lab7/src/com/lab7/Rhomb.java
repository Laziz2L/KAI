package com.lab7;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Rhomb extends Rectangle {

    public Rhomb(double x, double y, double l, double h) {
        super(x, y, l, h);
    }

    @Override
    public void Show(boolean sh, GraphicsContext gc) {
        if (sh) {
            gc.setFill(Color.PLUM);
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
