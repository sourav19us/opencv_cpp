import cv2 as cv
# read image
img = cv.imread('image1.jpg', 0)  # -1,0,1
# print image array
# print(img)
# show image
cv.imshow("image", img)
# wait key 5 sec
# cv.waitKey(5000)
#
k = cv.waitKey(0)

# Esc key value is 27
# keyboard key values link
# https://docstore.mik.ua/orelly/webprog/DHTML_javascript/0596004672_jvdhtmlckbk-app-b.html

if k == ord('q'):  # ord() expected a character only

    cv.destroyAllWindows()

elif k == ord('s'):
    cv.imwrite('image_write.jpg', img)
    cv.destroyAllWindows()
