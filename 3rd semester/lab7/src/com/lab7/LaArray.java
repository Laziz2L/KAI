package com.lab7;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;

import java.util.Arrays;

public class LaArray {
    private TFigure[] arr;
    private int c;

    public LaArray() {
        arr = new TFigure[10];
        c = 0;
    }

    public void Add(Canvas cnv) {
        c++;
        if (c==arr.length) {
            arr = Arrays.copyOf(arr, arr.length+10);
        }
        for (int i = 0; i<arr.length; i++) {
            if (arr[i]==null) {
                int r = 0;
                double g,v;
                do {
                    r = (int) Math.round(Math.random() * 10);
                } while (r==0 | r>5);

                g = Math.random()*100;
                v = Math.random()*100;
                switch (r){
                    case 1 :
                        arr[i] = new Circle((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                                (Math.random() * (cnv.getHeight()-2*(30 + g/2)) + (30 + g/2)), g);
                        break;
                    case 2 :
                        arr[i] = new Rectangle((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                                (Math.random() * (cnv.getHeight()-2*(30 + v/2)) + (30 + v/2)), g, v);
                        break;
                    case 3 :
                        arr[i] = new Ellipse((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                                (Math.random() * (cnv.getHeight()-2*(30 + v/2)) + (30 + v/2)), g, v);
                        break;
                    case 4 :
                        arr[i] = new Trap((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                                (Math.random() * (cnv.getHeight()-2*(30 + v/2)) + (30 + v/2)), g, v);
                        break;
                    case 5 :
                        arr[i] = new Rhomb((Math.random() * (cnv.getWidth()-2*(30 + g/2)) + (30 + g/2)),
                                (Math.random() * (cnv.getHeight()-2*(30 + v/2)) + (30 + v/2)), g, v);
                        break;

                }
                break;
            }
        }
    }

    public void ShowArr(GraphicsContext gc, boolean sh) {
        for (int i = 0; i<arr.length; i++) {
            if (arr[i]!=null) arr[i].Show(sh, gc);
        }
    }

    public void Move(int type, double dx, double dy, GraphicsContext gc) {
        switch (type) {
            case 0 :
                for (int i=0; i<arr.length; i++) {
                    if (arr[i]!=null){
                        arr[i].MoveTo(dx, dy, gc);
                    }
                }
                break;
            case 1 :
                for (int i=0; i<arr.length; i++) {
                    if ((arr[i] instanceof Circle)&!(arr[i] instanceof Ellipse)){
                        if (arr[i]!=null){
                            arr[i].MoveTo(dx, dy, gc);
                        }
                    }
                }
                break;
            case 2 :
                for (int i=0; i<arr.length; i++) {
                    if ((arr[i] instanceof Rectangle)&!(arr[i] instanceof Rhomb)&!(arr[i] instanceof Trap)){
                        if (arr[i]!=null){
                            arr[i].MoveTo(dx, dy, gc);
                        }
                    }
                }
                break;
            case 3 :
                for (int i=0; i<arr.length; i++) {
                    if (arr[i] instanceof Ellipse){
                        if (arr[i]!=null){
                            arr[i].MoveTo(dx, dy, gc);
                        }
                    }
                }
                break;
            case 4 :
                for (int i=0; i<arr.length; i++) {
                    if (arr[i] instanceof Trap){
                        if (arr[i]!=null){
                            arr[i].MoveTo(dx, dy, gc);
                        }
                    }
                }
                break;
            case 5 :
                for (int i=0; i<arr.length; i++) {
                    if (arr[i] instanceof Rhomb){
                        if (arr[i]!=null){
                            arr[i].MoveTo(dx, dy, gc);
                        }
                    }
                }
                break;
        }
    }

    public void Clear(GraphicsContext gc) {
        ShowArr(gc, false);
        arr = new TFigure[10];
        c = 0;
    }

    public void Iterator(int flag, Canvas cnv, GraphicsContext gc, Boolean sh, int type, double dx, double dy) {
        switch (flag) {
            case 1 :
                Add(cnv);
                break;
            case 2 :
                ShowArr(gc, sh);
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
