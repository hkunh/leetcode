力扣vscode修改保存路径：
* vscode ctrl + ,
* 搜索 leetcode.workspaceFolder
* 在 settings.json文件中添加或修改如下配置：
``` json
"leetcode.workspaceFolder": "D:/LeetCode/Problems"  // 替换为您想要保存的路径
```

| 模型 | 参数量 | 计算量 | dns3上听觉指标 | DNS1 no-reverb听觉指标 |
| :---:| :---: | :---: | :---: | :---: |
|deepfilternet2 （2022）|2.3M |355M MACS|（官方预训练模型，官方是在dns4上训练的）2.92| - |                
|deepfilternet3（2023） |2.3M | 355M MACS |（官方预训练模型，官方是在dns4上训练的）2.84 |（来自aTENNuate）2.58 |
|aTENNuate （2025）| 0.84M | 330M MACS | - | （dns1）2.98 |
|TSDT-SumAll （2025）| 0.56M | 478M MACS | - | (dns1)2.68 |
|mymodel | 1.2M | 314M macs | 2.84 |（在dns3上训练）3.01(???) |

上面的deepfilternet3 我自己使用官方预训练模型，跑DNS1 no-reverb， 测试出来也是2.6多
上面的指标都是听觉指标，代表模型降噪后的效果对于人耳实际听起来怎么样。越高越好
实际还有一个sisnr指标，这个指标代表信号的还原程度，对于比如降噪后有语音识别这类有帮助，但是对于降噪后人耳实际听觉无帮助。所以这个指标论文有的有报告，有的没报告
我自己的模型测试，发现在DNS1 no-reverb 听觉指标很高，但是实际对比deepfilternet3 TSDT-SumAll 的sisnr，就低了不少。但是aTENNuate 都直接不报告这个指标
在小的数据集voicebank上，我模型的听觉指标也比较高，可以说比上面的模型都高，但是sisnr也低。



| 模型 | 参数量 | 计算量 | voicebank上听觉指标 |
| :---: | :---: | :---: | :---: |
| deepfilternet2 (2022) | 2.3M | 355M MACS | (官方预训练模型，官方是在dns4上训练的) 3.08 |
| deepfilternet3 (2023) | 2.3M | 355M MACS | (官方预训练模型，官方是在dns4上训练的) 3.16 |
| aTENNuate (2025) | 0.84M | 330M MACS | 3.27 |
| TSDT-SumAll (2025) | 0.56M | 478M MACS | - |
| LiSenNet (2025) | 37k | 56M macs | 3.07 |
| FSPEN (2025) | 79k | 89M | 2.97 |
| LSENet (2025) | 40k | 240M MACS | 3.12 |

