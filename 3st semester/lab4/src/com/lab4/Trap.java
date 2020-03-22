package com.lab4;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Trap extends Rectangle {

    public Trap(double x, double y, double l, double h, int count) {
        super(x, y, l, h, count);
    }

    @Override
    public void Show(int sh, GraphicsContext gc) {
        if (sh==1) {
            gc.setFill(Color.ROSYBROWN);
            gc.fillPolygon(new double[] {getX()-this.getLength()/4, getX()+this.getLength()/4,
                            getX()+this.getLength()/2, getX()-this.getLength()/2},
                    new double[] {getY()-this.getHeight()/2, getY()-this.getHeight()/2,
                            getY()+this.getHeight()/2, getY()+this.getHeight()/2},
                    4);
        }
        else if (sh==2) {
            gc.setFill(Color.CHARTREUSE);
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
