import cv2 as cv

img = cv.imread('image1.jpg', 1)

img = cv.line(img, (50, 250), (300, 300), (100, 125, 255), 10)

img = cv.arrowedLine(img, (60, 60), (300, 300), (0, 25, 255), 10)

img = cv.rectangle(img, (0, 0), (250, 250), (0, 25, 250), 10)

img = cv.circle(img, (250, 250), 80, (0, 255, 0), -1)

img = cv.putText(img, "hello Y ", (50, 50), 5,
                 4, (250, 250, 250), 10, cv.LINE_AA)

cv.imshow('image', img)

cv.waitKey(0)
cv.destroyAllWindows()
