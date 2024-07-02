import cv2
from matplotlib import pyplot as plt

img = cv2.imread(input("Enter the image file to detect face: "))

img_grey = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'Haarcascade_frontalface_default.xml')
smile_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_smile.xml')

found = face_cascade.detectMultiScale(img_grey, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

number_found = len(found)

if number_found > 0:
    for (x, y, width, height) in found:
        cv2.rectangle(img_rgb, (x, y), (x + height, y + width), (0, 255, 0), 5)

        roi_grey = img_grey[y:y + height, x:x + width]
        roi_rgb = img_rgb[y:y + height, x:x + width]

        smiles = smile_cascade.detectMultiScale(roi_grey, scaleFactor=1.8, minNeighbors=20, minSize=(25, 25))

        if len(smiles) > 0:
            label = "Smiling"
            color = (0, 0, 0)
        else:
            label = "Not Smiling"
            color = (0, 0, 0)

        cv2.putText(img_rgb, label, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)
        cv2.rectangle(img_rgb, (x, y), (x + width, y + height), color, 2)
else:
    smiles = []
plt.subplot(1, 1, 1)
plt.imshow(img_rgb)
plt.show()

print(number_found, "faces found in the image")
print(len(smiles), "out of", number_found, "of these people were smiling")
