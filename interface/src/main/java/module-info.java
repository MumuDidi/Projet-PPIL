module main.synthese {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;


    opens main to javafx.fxml;
    exports main;
}