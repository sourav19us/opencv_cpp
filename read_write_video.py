import cv2 as cv

# 0,-1 for sytem camera , and for external  camera 1 ,2 ,3
# cap = cv.VideoCapture(0)
# for read a file
cap = cv.VideoCapture('song.mp4')

fourcc = cv.VideoWriter_fourcc(*'XVID')
out = cv.VideoWriter('video_write.avi', fourcc, 30, (640, 480))

while cap.isOpened():  # cap.isOpened() write true if file open

    ret, frame = cap.read()

    if ret == True:
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

        out.write(frame)

        # cv.imshow('video', frame)
        cv.imshow('video', gray)

    # 0xFF == ord('q'): for 64bit machine
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
out.release()
cv.destroyAllWindows()
