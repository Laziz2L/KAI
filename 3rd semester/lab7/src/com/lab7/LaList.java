package com.lab7;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;

public class LaList {
    private ListElement head;
    private ListElement tail;

    public LaList() {
        head = null;
        tail = null;
    }

    public void Add(Canvas cnv) {

        TFigure n;

        int r = 0;
        double g,v;
        do {
            r = (int) Math.round(Math.random() * 10);
        } while (r==0 | r>5);
        g = Math.random()*100;
        v = Math.random()*100;
        switch (r) {
            case 1 :
                n = new Circle((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                        (Math.random() * (cnv.getHeight()-2*(30 + g/2)) + (30 + g/2)), g);
                break;
            case 2 :
                n = new Rectangle((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                        (Math.random() * (cnv.getHeight()-2*(30 + v/2)) + (30 + v/2)), g, v);
                break;
            case 3 :
                n = new Ellipse((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                        (Math.random() * (cnv.getHeight()-2*(30 + v/2)) + (30 + v/2)), g, v);
                break;
            case 4 :
                n = new Trap((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                        (Math.random() * (cnv.getHeight()-2*(30 + v/2)) + (30 + v/2)), g, v);
                break;
            case 5 :
                n = new Rhomb((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                        (Math.random() * (cnv.getHeight()-2*(30 + v/2)) + (30 + v/2)), g, v);
                break;
            default :
                n= null;
                break;
        }

        ListElement newEl = new ListElement(n);
        if (tail==null) {
            head = newEl;
        } else {
            tail.setNextEl(newEl);
        }
        tail = newEl;
    }

    public void ShowList(GraphicsContext gc, boolean sh) {
        ListElement t = head;
        while (t!=null) {
            t.getFigure().Show(sh, gc);
            t = t.getNextEl();
        }
    }

    public void Move(int type, double dx, double dy, GraphicsContext gc) {
        ListElement t = head;
        switch (type) {
            case 0 :
                while (t!=null) {
                    t.getFigure().MoveTo(dx, dy, gc);
                    t = t.getNextEl();
                }
                break;
            case 1 :
                while (t!=null) {
                    if ((t.getFigure() instanceof Circle)&!(t.getFigure() instanceof Ellipse)){
                        t.getFigure().MoveTo(dx, dy, gc);
                    }
                    t = t.getNextEl();
                }
                break;
            case 2 :
                while (t!=null) {
                    if ((t.getFigure() instanceof Rectangle)&!(t.getFigure() instanceof Rhomb)&!(t.getFigure() instanceof Trap)){
                        t.getFigure().MoveTo(dx, dy, gc);
                    }
                    t = t.getNextEl();
                }
                break;
            case 3 :
                while (t!=null) {
                    if (t.getFigure() instanceof Ellipse){
                        t.getFigure().MoveTo(dx, dy, gc);
                    }
                    t = t.getNextEl();
                }
                break;
            case 4 :
                while (t!=null) {
                    if (t.getFigure() instanceof Trap){
                        t.getFigure().MoveTo(dx, dy, gc);
                    }
                    t = t.getNextEl();
                }
                break;
            case 5 :
                while (t!=null) {
                    if (t.getFigure() instanceof Rhomb){
                        t.getFigure().MoveTo(dx, dy, gc);
                    }
                    t = t.getNextEl();
                }
                break;
        }
    }

    public void Clear(GraphicsContext gc) {
        ShowList(gc, false);
        head = null;
        tail = null;
    }

    public void Iterator(int flag, Canvas cnv, GraphicsContext gc, Boolean sh, int type, double dx, double dy) {
        switch (flag) {
            case 1 :
                Add(cnv);
                break;
            case 2 :
                ShowList(gc, sh);
                break;
            case 3 :
                Move(type, dx, dy, gc);
                break;
            case 4 :
                Clear(gc);
                break;
        }
    }
}
