package day10_DepthFirstSearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")

public class Q4_MooTube {
    private static ArrayList<Integer[]>[] videoInfo;
    private static int videosConnected = 0;
    private static boolean[] connected;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int videoCount = Integer.parseInt(st.nextToken());
        int questionCount = Integer.parseInt(st.nextToken());
        videoInfo = new ArrayList[videoCount];
        connected = new boolean[videoCount];
        for (int i = 0; i < videoInfo.length; i++) {
            videoInfo[i] = new ArrayList<>();
        }
        for (int i = 0; i < videoCount - 1; i++) {
            st = new StringTokenizer(in.readLine());
            int video1 = Integer.parseInt(st.nextToken()) - 1;
            int video2 = Integer.parseInt(st.nextToken()) - 1;
            int relevance = Integer.parseInt(st.nextToken());
            Integer[] temp1 = {video2, relevance};
            videoInfo[video1].add(temp1);
            Integer[] temp2 = temp1.clone();
            temp2[0] = video1;
            videoInfo[video2].add(temp2);
        }
        for (int i = 0; i < questionCount; i++) {
            st = new StringTokenizer(in.readLine());
            int relevance = Integer.parseInt(st.nextToken());
            int start = Integer.parseInt(st.nextToken()) - 1;
            connected[start] = true;
            findVideos(relevance, start);
            System.out.println(videosConnected);
            videosConnected = 0;
            connected = new boolean[videoCount];
        }
    }
    private static void findVideos(int relevance, int currVideo) {
        if (currVideo < videoInfo.length) {
            for (int i = 0; i < videoInfo[currVideo].size(); i++) {
                int destination = videoInfo[currVideo].get(i)[0];
                if (!connected[destination]) {
                    if (videoInfo[currVideo].get(i)[1] >= relevance) {
                        connected[destination] = true;
                        videosConnected++;
                        findVideos(relevance, destination);
                    }
                }
            }
        }
    }
}
