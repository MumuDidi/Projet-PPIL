package main;

import java.util.ArrayList;
import java.util.List;

public class Group {
    private List<Shape> group_shapes = new ArrayList<> ();

    public Group(List<Shape> simple2) {
        this.group_shapes = List.copyOf(simple2);
    }

    public List<Shape> getList() {
        return this.group_shapes;
    }
}
