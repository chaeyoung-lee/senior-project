# CPSC 490: Senior Project

- Author: Chae Young Lee, EECS (chaeyoung.lee@yale.edu)
- Advisor: Prof. Lin Zhong, CS (lin.zhong@yale.edu)
- Website: https://zoo.cs.yale.edu/classes/cs490/22-23a/lee.chae_young.cl2322/

## Abstract

Modern mobile networks focus on virtualization to move away from specialized, dedicated hardwares installed at base stations to public, edge data centers. Massive MIMO is one of the key technologies of NextG mobile networks in improving spectral efficiency, however it is considered the worst obstacle towards achieving virtualized NextG networks. Agora is the world’s first software realization of the massive MIMO physical layer, yet a lot needs to be done to fully virtualize Agora. In this project, we show that Agora can be migrated to the cloud and operate in a resource-elastic manner to optimize deployment cost and maintain stable connection. We propose Resource Provisioner (RP) to adjust the amount of computing resources in real-time based on the network traffic. RP runs independently of Agora and communicates with the Agora and the cloud hypervisor to modify resource allocation during runtime. During deployment, IQ samples are transferred from a Remote Radio Unit (RRU) at base stations to the cloud using a high-speed fronthaul link. While Agora processes these network packets, RP aids Agora by allocating compute resources most optimal for the current network traffic without disrupting the main functionality of Agora. We demonstrate that the RP-aided Agora not only meets the real-time requirement within 5 milliseconds but also outperforms fixed-resource Agora mainly in connection stability and deployment cost. Additionally, we have resolved issues in the Agora codebase that hindered the implementation process. The refactored Agora code assumes a modular design concerned with memory safety and isolation. This project establishes a baseline for building a resource-elastic and intelligent MIMO physical layer that operates on the cloud.

## Deployment

Please read [AGORA_README.md](AGORA_README.md)