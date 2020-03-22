package com.lab7;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Trap extends Rectangle {

    public Trap(double x, double y, double l, double h) {
        super(x, y, l, h);
    }

    @Override
    public void Show(boolean sh, GraphicsContext gc) {
        if (sh) {
            gc.setFill(Color.ROSYBROWN);
            gc.fillPolygon(new double[] {getX()-this.getLength()/4, getX()+this.getLength()/4,
                            getX()+this.getLength()/2, getX()-this.getLength()/2},
                    new double[] {getY()-this.getHeight()/2, getY()-this.getHeight()/2,
                            getY()+this.getHeight()/2, getY()+this.getHeight()/2},
                    4);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillPolygon(new double[] {getX()-this.getLength()/4-1, getX()+this.getLength()/4+1,
                            getX()+this.getLength()/2+2, getX()-this.getLength()/2-2},
                    new double[] {getY()-this.getHeight()/2-1, getY()-this.getHeight()/2-1,
                            getY()+this.getHeight()/2+1, getY()+this.getHeight()/2+1},
                    4);
        }
    }
}
