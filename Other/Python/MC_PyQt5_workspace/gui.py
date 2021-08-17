from PyQt5.QtWidgets import *
from calculate import *

class Main(QWidget):
    def __init__(self):
        super().__init__()
        self.ui = Ui_calculator()
        self.ui.setupUi(self)
        self.ui.calculate_button.clicked.connect(self.calculated)
        
    def calculated(self):
        try:
            self.ui.result_box.setText(str(eval(self.ui.input_box_1.text() + self.ui.set_sign_combo_box.currentText() + self.ui.input_box_2.text())))
        except:
            QMessageBox.critical(QtWidgets.QMainWindow(), 'Error', 'Invalid Input!', QMessageBox.Ok)

if __name__ == '__main__':
    import sys
    app = QApplication(sys.argv)
    main = Main()
    main.show()
    sys.exit(app.exec_())