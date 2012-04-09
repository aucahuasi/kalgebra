import QtQuick 1.1

Rectangle
{
	color: "white"
	
	Button {
		text: "<-"
		anchors {
			bottom: parent.bottom
			right: parent.right
		}
		onClicked: parent.destroy()
		z: 5432
	}
}